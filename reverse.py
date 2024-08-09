def reverse_bits(n):
    # your code here
    numero = bin(n)
    str = ""
    cont = 0
    for num in numero:
        if cont == 1:
            str += num
        if num == "b":
            cont = 1
            
    str = str[::-1]
    numro = int(str,2)
    return numro
    
