extern echo(double);

def man(n)
    var f1, f2 = 1, next in
        if (n < 1) then
            echo(0)
        else
            echo(f1):
            for i = 1, i < n in
                echo(f2):
                next = f1 + f2:
                f1 = f2:
                f2 = next
            end
        end
    end
;