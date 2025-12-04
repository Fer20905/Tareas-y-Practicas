def greedy_change(amount, coins):
    coins = sorted(coins, reverse=True)
    result = []

    print(f"Cantidad: {amount}")
    print(f"Monedas disponibles: {coins}")

    for c in coins:
        while amount >= c:
            amount -= c
            result.append(c)

    return result


if __name__ == "__main__":
    coins = [50, 20, 10, 5, 2, 1]
    amount = 87
    resultado = greedy_change(amount, coins)

    print("Monedas entregadas:", resultado)
    print("Total de monedas:", len(resultado))
