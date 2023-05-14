def f(x y z)
    var a arrof 3
    in
        a[0] = -x:
        a[1] = -y:
        a[2] = -z:
        if a[0] > a[1]
            then if  a[0] > a[2]
                then a[0]
                else a[2]
            end
            else if a[1] > a[2]
                then a[1]
                else a[2]
            end
        end
    end
; 

def main()
    print(f(1, 2, 3)):
    print(f(20,80,2)):
    print(f(11,2,3))
;