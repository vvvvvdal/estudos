import pandas as pd
import matplotlib.pyplot as plt

dados = {
    'Vendedor':['Ana', 'Bruno', 'Carla', 'Daniel', 'Edu'],
    'Valor': [200, 250, 300, 230, 350]
}

df_vendas = pd.DataFrame(dados)
df_vendas['Comissao'] = 0.1*df_vendas['Valor']

grafico = plt.bar(df_vendas['Vendedor'], df_vendas['Valor'])

plt.title("Vendas por Vendedor")
plt.xlabel("Nome")
plt.ylabel("Valor")
plt.show()