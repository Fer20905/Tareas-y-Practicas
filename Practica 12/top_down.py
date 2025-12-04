memoria = {}

def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]

    if n == 0:
        memoria[0] = 0
        return 0
    if n == 1:
        memoria[1] = 1
        return 1

    valor = fibonacci_top_down(n - 1) + fibonacci_top_down(n - 2)
    memoria[n] = valor
    return valor


if __name__ == "__main__":
    num = 10
    print(f"Fibonacci Top-Down de {num} =", fibonacci_top_down(num))
    print("Memoria usada:", memoria)
