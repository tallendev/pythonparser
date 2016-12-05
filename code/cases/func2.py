x = 7
def f():
    def g():
        global x
        x += 1
        print x
    g()

def g():
    print x

f()
g()

def a():
    x = 5
    def b():
        def c():
            def d():
                def e():
                    print x
                e()
            d()
        c()
    b()

a()
