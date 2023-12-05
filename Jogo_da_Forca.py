import random

def dicionario():
    dic = ['amarelo','amor', 'branco', 'blusa', 'faca', 'girafa', 'janela', 'limonada','meia','noite', 'oculos', 'parque', 'rato', 'umbigo']
    return dic
     
def escolher_palavra():
    palavras = random.choice(dicionario())
    return palavras
        
def exibir_palavra(palavrasplit,palavra_oculta, palpite):
    
    for i in range(len(palavrasplit)):
            if palavrasplit[i] == palpite:
                palavra_oculta[i] = palpite
    return palavra_oculta

def main():
    palavra = escolher_palavra()
    palavrasplit = list(palavra)
    # Caso queira ver a palavra escolhida
    # print(palavrasplit)
    
    print("Bem-vindo ao Jogo da Forca!\nO Jogo da Forca é um desafio que testará seu conhecimento de palavras e letras. Você terá que adivinhar a palavra oculta, letra por letra, antes que suas chances se esgotem.\nVocê terá x tentativas para adivinhar a palavra dependendo da dificuldade escolhida, e a cada tentativa errada, parte de um boneco será desenhada na forca. Se o boneco estiver completo antes de você adivinhar a palavra, você perderá o jogo.\nBoa sorte! Vamos começar!")
    print("_________________________________________________________________________________")
    
    dif = int(input("Diga a dificuldade que você quer jogar(1 = Fácil, 2 = Médio, 3 = dificil): "))
    if dif == 1:
        corpo = ['Cabeça', 'Tronco', 'Braço direito','Braço esquerdo', 'Perna direita', 'Perna esquerda']
        tentativas = len(corpo)
        pontos = 6
        print("Você escolheu o modo Fácil")
        
    elif dif == 2:
        corpo = ['Cabeça', 'Tronco', 'Braço direito', 'Braço esquerdo', 'Pernas']
        tentativas = len(corpo)
        pontos = 8
        print("Você escolheu o modo Intermediário")
        
    elif dif == 3:    
        corpo = ['Cabeça', 'Tronco', 'Braços', 'Pernas']
        tentativas = len(corpo)
        pontos = 10
        print("Você escolheu o modo Difícil")
        
    else:
        print("Selecione uma dificuldade válida.")
# -------------------------------------------------------------------------------------------------------------
    print("_________________________________________________________________________________")
    print(f"Dica: A palavra tem {len(palavrasplit)} letras.")

    palavra_oculta = ['_' for _ in palavrasplit] 
    
    while True:
        if tentativas == 0:
            print("Corpo está completo, você perdeu...")
            print(f"SUA PONTUAÇÃO FOI {pontos} PONTOS")
            break
 
        elif palavra_oculta == palavrasplit:
            print(f"PARABÉNS VOCÊ ACERTOU A PALAVRA! Ela era {palavra.capitalize()}") 
            pontos += 5
            print(f"SUA PONTUAÇÃO FOI {pontos} PONTOS")
            break
        
        else:
            palpite = input("Tente advinhar uma letra da palavra: ")
            if len(palpite) != 1:
                print("Digite apenas uma letra.")
                continue
            
            if exibir_palavra(palavrasplit,palavra_oculta,palpite) != palavrasplit: 
                if palpite in palavrasplit:
                    print("Essa letra está na palavra.")
                    pontos += 1
                    print(f"Letras certas:{palavra_oculta}")
                    
                else:
                    print("Essa letra NÃO está na palavra.")
                    tentativas -=1
                    pontos -= 3
                    print(f"A {corpo.pop(0)} foi adicionada.")
                    
            print("_________________________________________________________________________________")      
                            
     
if __name__ == '__main__':
    main()