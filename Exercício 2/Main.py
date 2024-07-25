def fatores_primos(numero):
    fatores = []
    divisor = 2
    while divisor <= numero:
        if numero % divisor == 0:
            fatores.append(divisor)
            numero //= divisor
        else:
            divisor += 1
    return fatores

def fatores_comuns(numero1, numero2):
    fatores1 = fatores_primos(numero1)
    fatores2 = fatores_primos(numero2)
    fatores_comuns = [fator for fator in fatores1 if fator in fatores2]
    return fatores_comuns

numero1 = int(input("Digite o Primeiro número inteiro: "))
numero2 = int(input("Digite o Segundo número inteiro: "))
fatores_comuns_lista = fatores_comuns(numero1, numero2)
print(f"Os Fatores Comuns de {numero1} e {numero2} são: {fatores_comuns_lista}")
