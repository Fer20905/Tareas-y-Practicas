memoria = {1: 0, 2: 1}  

def fibonacci(n):
    if n in memoria:
        return memoria[n]
    
    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2)
    
    return memoria[n]

posiciones = [7, 21, 40, 71, 94]

print("Valores de Fibonacci en las posiciones solicitadas:\n")
for p in posiciones:
    print(f"F({p}) = {fibonacci(p)}")
