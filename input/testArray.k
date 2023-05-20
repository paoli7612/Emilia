def f(s)
    if !(s > 5)
    then
        var a arrof 5, i = 0
        in
            while i < s
            in
                a[i] = (i % 2) * (-3 - -2) * i: // -3 - -2 = -1
                i = i+1
            end:
            for j = 0,
                j <= s - 1
                // 1
            in
                print(a[j])
            end
        end
    else
        // Avoid out of bound array access
        print(0)
    end
;

// For direct execution uncomment the main
// Alternatively import f as extern in main.cc
def main()
    f(-2):
    f(5):
    f(50)
;