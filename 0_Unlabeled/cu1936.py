num1, num2 = map(int, input().split())

def foo(num, list):
    list.append(num)
    if num == 1:
        return list
    return foo(int(num/2), list)

def foo2(num1list, num2list, pos = 0):
    if num1list[0] == num2list[0]:
        return 0
    if num1list[len(num1list)-pos-1] != num2list[len(num2list)-pos-1]:
        return (len(num1list)-pos) + (len(num2list)-pos)
    return foo2(num1list, num2list, pos + 1)

print(foo2(foo(num1, []), foo(num2, [])))
