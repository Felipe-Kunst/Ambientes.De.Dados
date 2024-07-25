from datetime import datetime

class Funcionario:
    def __init__(self, nome: str, data_contratacao: str, salario: float):
        self.nome = nome
        self.data_contratacao = datetime.strptime(data_contratacao, "%Y-%m-%d")
        self.salario = salario

    def aumentar_salario(self, percentual: float):
        self.salario += self.salario * (percentual / 100)

    def __str__(self):
        return f'Funcionario: {self.nome}, Data de Contratação: {self.data_contratacao.date()}, Salário: R${self.salario:.2f}'


class Gerente(Funcionario):
    def aumentar_salario(self, percentual: float):
        anos_de_servico = (datetime.now() - self.data_contratacao).days // 365
        percentual_final = percentual + anos_de_servico
        self.salario += self.salario * (percentual_final / 100)

    def __str__(self):
        return f'Gerente: {self.nome}, Data de Contratação: {self.data_contratacao.date()}, Salário: R${self.salario:.2f}, Anos de Serviço: {(datetime.now() - self.data_contratacao).days // 365}'


funcionario = Funcionario("Felipe", "2020-01-15", 3000.00)
gerente = Gerente("Maria", "2015-06-10", 5000.00)

print("Antes do aumento:")
print(funcionario)
print(gerente)

funcionario.aumentar_salario(10)
gerente.aumentar_salario(10) 

print("\nDepois do aumento:")
print(funcionario)
print(gerente)

def aplicar_aumento_e_mostrar_salario(funcionario: Funcionario, percentual: float):
    funcionario.aumentar_salario(percentual)
    print(funcionario)

print("\nAplicando aumento polimorficamente:")
aplicar_aumento_e_mostrar_salario(funcionario, 5)  
aplicar_aumento_e_mostrar_salario(gerente, 5) 
