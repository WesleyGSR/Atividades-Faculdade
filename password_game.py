import tkinter as tk
import re

def verificar_senha_automaticamente(event):
    senha = entry_senha.get()
    cor_verde = 'pale green'
    cor_vermelha = 'salmon'


    # REGRA 1 /////////////////////////////////////////////////////////////////////////////
    if len(senha) < 8:
        entry_senha.config(bg=cor_vermelha)
        label_status['text'] = "regra 1: sua senha deve conter pelo menos 8 caracteres!"
        alterar_fundo("fechado.png")
        return
    

    # REGRA 2 /////////////////////////////////////////////////////////////////////////////
    if not any(char.isdigit() for char in senha):
        label_status['text'] = "regra 2: sua Password deve incluir pelo menos um número!"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return
    

    # REGRA 3 /////////////////////////////////////////////////////////////////////////////
    if not re.search("[!@#$%^&*()_+=\-[\]{};:,.<>?]", senha):
        label_status['text'] = "regra 3: sua senha deve incluir um caractere especial!"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return


    # REGRA 4 /////////////////////////////////////////////////////////////////////////////
    if not any(char.isupper() for char in senha):
        label_status['text'] = "regra 4: sua senha deve incluir pelo menos uma letra maiúscula!(atenção as maiúsculas!!)"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return


    # REGRA 5 /////////////////////////////////////////////////////////////////////////////
    numeros_senha = [int(num) for num in re.findall(r'\d', senha)]
    if sum(numeros_senha) != 24:  # 4 fatorial é igual a 24
        label_status['text'] = "regra 5: a soma dos números da sua senha deve ser o resultado de 4(fatorial)!"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return


    # REGRA 6 /////////////////////////////////////////////////////////////////////////////
    dias_semana = {
        'segunda-feira': 1,
        'terça-feira': 2,
        'quarta-feira': 3,
        'quinta-feira': 4,
        'sexta-feira': 5,
        'sábado': 6,
        'domingo': 7
    }

    if not any(dia.lower() in senha.lower() for dia in dias_semana.keys()):
        label_status['text'] = "regra 6: sua senha deve conter um dia da semana!"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return
    

    # REGRA 7 /////////////////////////////////////////////////////////////////////////////
    if '3' not in senha:
        label_status['text'] = "regra 7: sua senha deve incluir em decimal o valor binario 0011 "
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return
    

    # REGRA 8 /////////////////////////////////////////////////////////////////////////////
    if not re.search("[IVXLCDM]", senha):
       label_status['text'] = "regra 8: sua senha deve incluir um número romano!"
       entry_senha.config(bg=cor_vermelha)
       alterar_fundo("fechado.png")
       return
    

    # REGRA 9 /////////////////////////////////////////////////////////////////////////////
    if 'VA' not in senha:
       label_status['text'] = "regra 9: sua senha deve incluir a sigla do menor país do World!"
       entry_senha.config(bg=cor_vermelha)
       alterar_fundo("fechado.png")
       return


    # REGRA 10 /////////////////////////////////////////////////////////////////////////////
    fibonacci = [ 1, 2, 3, 5, 8]
    if not all(int(num) in fibonacci for num in senha if num.isdigit()):
        label_status['text'] = "regra 10: os números da sua senha deVem estar presentes na sequência de Fibonacci."
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return



    # REGRA 11 /////////////////////////////////////////////////////////////////////////////
    if 'L' not in senha:
      label_status['text'] = "regra 11: sua senha deve incluir o último termo da equação de drake!"
      entry_senha.config(bg=cor_vermelha)
      alterar_fundo("fechado.png")
      return

   
   # REGRA 12 /////////////////////////////////////////////////////////////////////////////
    soma_romanos = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
    soma = 0
    for i in senha:
        soma += soma_romanos.get(i,0)
    if soma != 191:
        label_status['text'] = "regra 12: a soma dos números romanos deve ser igual a 191."
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return

    # REGRA 13 /////////////////////////////////////////////////////////////////////////////
    if 'IFCE' not in senha:
        label_status['text'] = "regra 13: sua senha deve incluir: .. ..-. -.-. . "
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return
    
    
    # REGRA 14 //////////////////////////////////////////////////////////////////////////////
    if 'PWVF' not in senha:
        label_status['text'] = "desafio Final: (atenção às maiúsculas)"" você lembra?"
        entry_senha.config(bg=cor_vermelha)
        alterar_fundo("fechado.png")
        return
    
    # CONCLUIDO /////////////////////////////////////////////////////////////////////////////
    label_status['text'] = "PassWord VeryFy finalizado!"
    entry_senha.config(bg=cor_verde)
    imagem_aberto = tk.PhotoImage(file="aberto.png")
    label_fundo.configure(image=imagem_aberto)
    label_fundo.image = imagem_aberto

def alterar_fundo(nome_arquivo):
    nova_imagem = tk.PhotoImage(file=nome_arquivo)
    label_fundo.configure(image=nova_imagem)
    label_fundo.image = nova_imagem

# Interface gráfica
root = tk.Tk()
root.title("PassWord-VeryFy-Game")
root.geometry('620x620')

imagem_fundo = tk.PhotoImage(file="fechado.png")
label_fundo = tk.Label(root, image=imagem_fundo)
label_fundo.place(x=0, y=0, relwidth=1, relheight=1)

label_instrucao = tk.Label(root, text="PassWord-VeryGame")
label_instrucao.pack(pady=(0, 200))

entry_senha = tk.Entry(root, show="", borderwidth=2, relief="solid")
#entry_senha = tk.Entry(root, show="")
entry_senha.pack(pady=90)
entry_senha.focus_set()

label_status = tk.Label(root, text="")
label_status.pack(pady=(0, 0))

# VERIFICADOR
entry_senha.bind('<KeyRelease>', verificar_senha_automaticamente)

root.mainloop()
