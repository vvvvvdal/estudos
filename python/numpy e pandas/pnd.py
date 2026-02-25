import pandas as pd

dados = {
    'Vendedor':['Ana', 'Bruno', 'Carla', 'Daniel', 'Edu'],
    'Valor': [200, 250, 300, 230, 350]
}

df_vendas = pd.DataFrame(dados)

df_vendas['Comissao'] = 0.1*df_vendas['Valor']

print(df_vendas)

total = df_vendas['Valor'].sum()
media = df_vendas['Comissao'].mean()
max = df_vendas['Valor'].max()

print(total, media, max)