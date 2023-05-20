def printFibonacciNumbers(n)
    var f1, 
        f2 = 1,
        next
    in
        if (n < 1)
        then
            print(0)
        else
            print(f1):
            for i = 1, 
                i < n
            in
                print(f2):
                next = f1 + f2:
                f1 = f2:
                f2 = next
            end
        end
    end
;

def main()
    printFibonacciNumbers(800)  :
    printFibonacciNumbers(0)   :
    printFibonacciNumbers(-5)
;