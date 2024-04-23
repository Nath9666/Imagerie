# Commande linux importante

## Commande de base

- `man` : Affiche le manuel d'une commande	
```bash
man ls
```
Affiche le manuel de la commande ls.

- `clear` : Efface l'écran
```bash
clear
```
Efface l'écran du terminal.

- `exit` : Quitte le terminal
```bash
exit
```
Quitte le terminal.

- `echo` : Affiche un message
```bash
echo "Hello World"
```
Affiche le message "Hello World".

- `date` : Affiche la date et l'heure
```bash
date
```
Affiche la date et l'heure.

- `cal` : Affiche le calendrier
```bash
cal
```
Affiche le calendrier du mois en cours.

- `bc` : Calculatrice
```bash
bc -l
```
Ouvre une calculatrice.

- `history` : Affiche l'historique des commandes
```bash
history
```
Affiche l'historique des commandes.

- `sudo` : Exécute une commande en tant qu'administrateur
```bash
sudo apt-get update
```
Met à jour la liste des paquets disponibles.

## Navigation

- `pwd` : Affiche le répertoire courant
```bash
pwd
```
Affiche le répertoire courant.

- `ls` : Liste les fichiers et répertoires
```bash
ls
```
Liste les fichiers et répertoires du répertoire courant.

- `cd` : Change de répertoire
```bash
cd /chemin/vers/le/dossier
```
Change de répertoire.

- `cd ..` : Remonte d'un niveau
```bash
cd ..
```
Remonte d'un niveau dans l'arborescence.

- `cd ~` : Retourne au répertoire personnel
```bash
cd ~
```
Retourne au répertoire personnel de l'utilisateur.

- `mkdir` : Crée un répertoire
```bash
mkdir nom_dossier
```
Crée un répertoire avec le nom spécifié.

- `rmdir` : Supprime un répertoire
```bash
rmdir nom_dossier
```
Supprime un répertoire vide.

- `rm -r` : Supprime un répertoire et son contenu
```bash
rm -r nom_dossier
```

- `cp` : Copie des fichiers et répertoires
```bash
cp fichier1 fichier2
```
Copie le fichier1 dans le fichier2.

- `mv` : Déplace des fichiers et répertoires
```bash
mv fichier1 fichier2
```
Déplace le fichier1 dans le fichier2.

- `touch` : Crée un fichier vide
```bash
touch fichier.txt
```

- `cat` : Affiche le contenu d'un fichier
```bash
cat fichier.txt
```
Affiche le contenu du fichier.

- `less` : Affiche le contenu d'un fichier page par page
```bash
less fichier.txt
```
Affiche le contenu du fichier page par page.

- `head` : Affiche les premières lignes d'un fichier
```bash
head fichier.txt
```
Affiche les premières lignes du fichier.

- `tail` : Affiche les dernières lignes d'un fichier
```bash
tail fichier.txt
```
Affiche les dernières lignes du fichier.

- `grep` : Recherche un motif dans un fichier
```bash
grep motif fichier.txt
```
Recherche le motif dans le fichier.

- `find` : Recherche des fichiers
```bash
find /chemin -name "nom_fichier"
```
Recherche le fichier avec le nom spécifié dans le chemin spécifié.

## Gestion des processus

- `ps` : Affiche les processus en cours d'exécution
```bash
ps
```
Affiche les processus en cours d'exécution.

- `top` : Affiche les processus en cours d'exécution en temps réel
```bash
top
```
Affiche les processus en cours d'exécution en temps réel.

- `kill` : Arrête un processus
```bash
kill PID
```

- `killall` : Arrête un processus par son nom
```bash
killall nom_processus
```

- `bg` : Met un processus en arrière-plan
```bash
bg PID
```

- `fg` : Ramène un processus en premier plan
```bash
fg PID
```

## Gestion des utilisateurs

- `who` : Affiche les utilisateurs connectés
```bash
who
```

- `whoami` : Affiche le nom de l'utilisateur courant
```bash
whoami
```

- `su` : Change d'utilisateur
```bash
su nom_utilisateur
```

- `sudo` : Exécute une commande en tant qu'administrateur
```bash
sudo commande
```

- `passwd` : Change le mot de passe de l'utilisateur
```bash
passwd
```

## Reseau

- `ifconfig` : Affiche les informations réseau
```bash
ifconfig
```

- `ping` : Envoie des paquets à une adresse IP
```bash
ping adresse_ip
```

- `wget` : Télécharge un fichier depuis une URL
```bash
wget url
```

- `curl` : Récupère le contenu d'une URL
```bash
curl url
```

- `ssh` : Se connecte à un serveur distant
```bash
ssh utilisateur@adresse_ip
```

- `scp` : Copie des fichiers entre deux ordinateurs
```bash
scp fichier utilisateur@adresse_ip:/chemin/destination
```