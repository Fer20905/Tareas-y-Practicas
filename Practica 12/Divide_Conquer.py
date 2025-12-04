def quicksort(lista):
    if len(lista) <= 1:
        return lista

    pivote = lista[len(lista) // 2]  
    menores = []
    iguales = []
    mayores = []

    for x in lista:
        if x < pivote:
            menores.append(x)
        elif x == pivote:
            iguales.append(x)
        else:
            mayores.append(x)

    return quicksort(menores) + iguales + quicksort(mayores)


if __name__ == "__main__":
    datos = [5, 2, 9, 1, 7, 3]
    print("Lista original:", datos)
    print("Lista ordenada (QuickSort):", quicksort(datos))
