x = 7
def f():
    def g():
        global x
        x += 1
        print x
    g()
f()
