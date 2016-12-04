x = 7
def f():
    def g():
        x += 1
        print x
    g()
f()
