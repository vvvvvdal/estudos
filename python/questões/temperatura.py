def validar_temperatura(temperatura_str):
    try:
        return float(temperatura_str)
    except ValueError:
        return "Valor inválido"