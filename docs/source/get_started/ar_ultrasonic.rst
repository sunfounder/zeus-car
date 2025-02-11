.. note::  

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, d’Arduino et de l’ESP32 avec d’autres passionnés.  

    **Pourquoi nous rejoindre ?**  

    - **Support d’experts** : Obtenez de l’aide pour résoudre vos problèmes après-vente et relevez vos défis techniques grâce à notre communauté et notre équipe.  
    - **Apprenez & partagez** : Échangez des conseils et tutoriels pour perfectionner vos compétences.  
    - **Aperçus exclusifs** : Profitez d’un accès anticipé aux annonces de nouveaux produits et à des avant-premières exclusives.  
    - **Réductions spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.  
    - **Promotions et cadeaux festifs** : Participez à des jeux-concours et à des offres spéciales à l’occasion des fêtes.  

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !  

10. Ultrason  
==============================

Dans ce projet, vous apprendrez à lire la distance détectée par le module ultrasonique.  

**Comment procéder ?**  

#. L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Ainsi, lors du téléversement du code, il est nécessaire de déconnecter l'ESP32-CAM pour éviter tout conflit ou problème potentiel.  

    .. image:: img/unplug_cam.png  
        :width: 400  
        :align: center  

#. Ouvrez le fichier ``10_ultrasonic.ino`` situé sous le chemin ``zeus-car-main\examples\10_ultrasonic``.  

    .. raw:: html  

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b3c702d7-2d4e-48fe-8d8d-7d20f70c9e45/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>  

#. Une fois le code téléversé avec succès, mettez l’interrupteur d’alimentation sur ON pour démarrer la Zeus Car.  

    .. note::  
        Ne débranchez pas l'USB à cette étape, car vous devez vérifier les données du module ultrasonique sur votre ordinateur.  

#. Ouvrez le moniteur série et assurez-vous que le débit en bauds actuel est réglé sur 115200. Il est recommandé de cliquer sur l’icône **Toggle Autoscroll** afin de toujours voir les dernières données affichées.  

   * Vous devriez voir apparaître des données comme ``distance: 21.11  is_obstacle: 0``.  
   * Si un obstacle se trouve à moins de 20 cm, la valeur ``is_obstacle: 0`` passera à ``is_obstacle: 1``.  

    .. image:: img/ar_ultrasonic.png  

