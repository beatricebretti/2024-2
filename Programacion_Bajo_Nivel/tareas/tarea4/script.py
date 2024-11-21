import criba

num = int(input("Ingrese un número: "))
count = criba.criba(num)
print(f"Cantidad de números primos menores o iguales a {num}: {count}")