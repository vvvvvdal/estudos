import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dados = {
    'Livros': ['Python Intro', 'Data Science', 'Machine Learning', 'Big Data', 'Redes Neurais'],
    'Vendas': [12, 5, 8, 20, 3],
    'Preco': [50, 120, 90, 40, 150]
}

livros = pd.DataFrame(dados)

livros['Total'] = livros['Vendas'] * livros['Preco']

best_seller = livros[livros['Total'] > 500]

plt.bar(best_seller['Livros'], best_seller['Total'])
plt.title("Livros Best Sellers")
plt.xlabel("Nome")
plt.ylabel("Vendas")
plt.show()