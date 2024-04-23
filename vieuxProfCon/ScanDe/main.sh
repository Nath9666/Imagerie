# Chemin vers le répertoire à scanner
dir_to_scan="/chemin/vers/le/répertoire"

# Nom de la configuration rclone pour OneDrive
onedrive_config="nomDeLaConfiguration"

# Chemin vers le répertoire de destination sur OneDrive
onedrive_dest="/chemin/vers/le/répertoire/de/destination"

# Boucle infinie
while true; do
    # Pour chaque fichier dans le répertoire
    for file in "$dir_to_scan"/*; do
        # Vérifie si le fichier a été modifié dans la dernière minute
        if [ "$(find "$file" -mmin -1)" ]; then
            # Si oui, copie le fichier sur OneDrive
            rclone copy "$file" "$onedrive_config":"$onedrive_dest"
        fi
    done

    # Attend 60 secondes avant de scanner à nouveau
    sleep 60
done