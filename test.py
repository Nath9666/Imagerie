import json
import random
import tkinter as tk
from tkinter import messagebox

# Charger les définitions à partir de definitions.json
with open('definitions.json', 'r') as f:
    definitions = json.load(f)

# Créer une liste pour stocker les scores
scores = []

# Créer une liste de toutes les définitions
all_definitions = list(definitions.values())

# Créer une fenêtre Tkinter
root = tk.Tk()

# Créer un widget Text pour afficher la question et les réponses
text = tk.Text(root)
text.pack()

def ask_question():
    if definitions:
        key, value = definitions.popitem()
        incorrect_answers = random.sample([d for d in all_definitions if d != value], 3)
        answers = [value] + incorrect_answers
        random.shuffle(answers)
        text.insert('end', f"{key} ?\n")
        for i, answer in enumerate(answers):
            text.insert('end', f"{i + 1}. {answer}\n")
        return value, answers
    else:
        messagebox.showinfo("Fin du questionnaire", "Vos scores ont été enregistrés dans scores.json.")
        root.quit()

correct_answer, answers = ask_question()

def check_answer():
    global correct_answer, answers
    user_answer = int(answer_entry.get()) - 1
    if answers[user_answer] == correct_answer:
        text.insert('end', "Bonne réponse!\n", 'correct')
        scores.append(1)
    else:
        text.insert('end', "Mauvaise réponse.\n", 'incorrect')
        scores.append(0)
    correct_answer, answers = ask_question()

# Créer un widget Entry pour l'entrée de l'utilisateur
answer_entry = tk.Entry(root)
answer_entry.pack()

# Créer un bouton pour soumettre la réponse
submit_button = tk.Button(root, text="Soumettre", command=check_answer)
submit_button.pack()

# Configurer les tags pour le texte coloré
text.tag_config('correct', foreground='green')
text.tag_config('incorrect', foreground='red')

# Lancer la boucle principale de Tkinter
root.mainloop()

# Enregistrer les scores dans scores.json
with open('scores.json', 'w') as f:
    json.dump(scores, f)