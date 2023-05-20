def obscure(x y z i)
    var x, y, z, i = 5
    in
        print(x = 3):
        print(x)    :
        print(y)    :
        print(z)    :
        print(i)    :
        for i = 10, i < 13, 2
        in 
            print(i)
        end :
        print(i)
    end :
    print(x)    :
    print(y)    :
    print(z)    :
    print(i)    
;

def main()
    obscure(20, 20, 20, 20)
;