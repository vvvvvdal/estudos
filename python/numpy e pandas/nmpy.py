import numpy as np

dados = [150, 200, 250, 180, 300]

vendas = np.array(dados)

vendas += 50

total = vendas.sum()
media = vendas.mean()
max = vendas.max()
min = vendas.min()

print(total, media, max, min,"\n")
print(vendas[vendas>250])