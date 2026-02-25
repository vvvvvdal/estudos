def filtrar_leituras_acima_limite(leituras, limite):
    lista = []

    for i in leituras:
        if(i>limite):
            lista.append(i)

    return lista

