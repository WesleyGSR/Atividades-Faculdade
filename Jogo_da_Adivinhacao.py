import random
def main():
    info = 'JOGO DA ADVINHAÇÃO:\n Você terá algumas rodadas para advinhar o número secreto, a cada tentativa você receberá uma ajuda perderá x pontos.\n BOA SORTE!'
    print(info)
    
    num_secreto = random.randint(1,101)
    rodada = 0
    dificuldade = int(input("Escolha a dificuldade (1)Fácil (2)Intermediário (3)Difícil: "))
    
    if dificuldade == 1:
        tentativas = 20
        pontuacao = 15
    elif dificuldade == 2:
        tentativas =  10
        pontuacao = 20
    elif dificuldade == 3:
        tentativas = 5
        pontuacao = 25
    else:
        print("Escolha uma dificuldade válida.")
           
    for t in range(tentativas):
        print(f"Você está na rodada {rodada + 1} tentativa de {tentativas}")
        chute = int(input("Digite um número: "))
        if 0 < chute <= 100:
            if chute == num_secreto:
                pontuacao += 5
                print(f"Parabéns você acertou! Sua pontuação foi {pontuacao}!")
                print(50*"-")
                break
                
            elif chute < num_secreto:
                print("Você chutou um número MENOR que o número secreto. Tente novamente")
                pontuacao -= 2
                rodada += 1
                print(50*"-")  
                  
            else:
                print("Você chutou um número MAIOR que o número secreto. Tente novamente")
                pontuacao -= 2
                rodada += 1
                print(50*"-")
                
        else:
            print("Tente um número de 1 a 100")     
               
if __name__ == '__main__':
    main()    