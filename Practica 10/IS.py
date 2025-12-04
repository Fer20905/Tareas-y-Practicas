def insertion_sort(arr):
    print("Lista original:", arr)

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        # Recorrer la parte ordenada
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    print("Lista ordenada:", arr)
    return arr


if __name__ == "__main__":
    lista = [5, 2, 9, 1, 3]
    insertion_sort(lista)
