def fact(x)
    if x <= 1
    then
        1
    else
        x * fact(x-1)
    end
;

def main()
    print(fact(150))
;
