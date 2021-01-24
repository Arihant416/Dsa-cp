def fib(num, obj={}):
    if num in obj:
        return obj[num]
    if num <= 1:
        return num
    if num == 2:
        return 1
    obj[num] = fib(num-1, obj) + fib(num-2, obj)
    return obj[num]


num = int(input())
print(fib(num))
