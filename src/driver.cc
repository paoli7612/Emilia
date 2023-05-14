#include "driver.hh"
#include "AST/RootAST.hh"
#include "AST/ExprAST.hh"
#include "AST/FunctionAST.hh"
#include "AST/Utils/LogError.hh"

/*************************** Driver class *************************/
driver::driver() : trace_parsing(false), trace_scanning(false), ast_print(false)
{
	context = new LLVMContext;
	module = new Module("Kaleidoscope", *context);
	builder = new IRBuilder(*context);
};

int driver::parse(const std::string &f)
{
	file = f;
	location.initialize(&file);
	scan_begin();
	yy::parser parser(*this);
	parser.set_debug_level(trace_parsing);
	int res = parser.parse();
	scan_end();
	return res;
}

void driver::codegen()
{
	if (ast_print)
		root->visit();
	std::cout << std::endl;
	root->codegen(*this);
};

/********************** Handle Top Expressions ********************/
Value *TopExpression(ExprAST *E, driver &drv)
{
	// Crea una funzione anonima anonima il cui body è un'espressione top-level
	// viene "racchiusa" un'espressione top-level
	E->toggle(); // Evita la doppia emissione del prototipo
	PrototypeAST *Proto = new PrototypeAST(
		"__espr_anonima" + std::to_string(++drv.Cnt),
		std::vector<std::string>()
	);
	Proto->noemit();
	FunctionAST *F = new FunctionAST(std::move(Proto), E);
	auto *FnIR = F->codegen(drv);
	FnIR->eraseFromParent();
	return nullptr;
};

AllocaInst *CreateEntryBlockAlloca(
	driver& drv,
	Function *TheFunction,
	const std::string &VarName,
	const Value* ArraySize
)
{
	IRBuilder<> TmpB(
		&TheFunction->getEntryBlock(),
		TheFunction->getEntryBlock().begin()
	);
	
	Value* ActualSize = (Value*)ArraySize;
	if(!ArraySize)
		return TmpB.CreateAlloca(
			Type::getDoubleTy(*drv.context),
			0,
			VarName.c_str()
		);


	return TmpB.CreateAlloca(
		Type::getDoubleTy(*drv.context), 
		ActualSize, 
		VarName.c_str()
	);
}