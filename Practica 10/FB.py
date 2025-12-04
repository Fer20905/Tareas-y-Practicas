import itertools
import string

def brute_force_password(target, length):
    chars = string.digits  # Solo números 0-9

    print(f"Buscando contraseña de {length} dígitos...")
    contador = 0

    for combo in itertools.product(chars, repeat=length):
        attempt = "".join(combo)
        contador += 1

        if attempt == target:
            print(f"Contraseña encontrada: {attempt}")
            print(f"Intentos realizados: {contador}")
            return attempt

    print("No encontrada.")
    return None


if __name__ == "__main__":
    # Puedes cambiar estas contraseñas de ejemplo:
    brute_force_password("1234", 4)
    # brute_force_password("12345678", 8)
    # brute_force_password("9876543210", 10)
