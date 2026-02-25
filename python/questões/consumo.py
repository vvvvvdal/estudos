def calcular_media_consumo(consumo_maquinas):
    media = 0.0

    if(len(consumo_maquinas) == 0): return media

    for i in consumo_maquinas.values():
        media += i

    media /= len(consumo_maquinas)

    return media