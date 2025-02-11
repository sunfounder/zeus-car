.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

6. Lumières du véhicule
==========================

Dans ce projet, vous pourrez utiliser la télécommande pour contrôler les bandes lumineuses RGB situées sous la voiture et leur faire afficher différentes couleurs.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/car_light.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``6_car_light.ino`` sous le chemin ``zeus-car-main\examples\6_car_light``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

#. Vous pouvez maintenant utiliser les touches numériques 1 à 9 de la télécommande pour allumer les lumières du véhicule en différentes couleurs. Appuyez sur 0 pour éteindre les lumières et sur |ir_return| pour activer un cycle de couleurs. Les touches 1 à 9 correspondent aux couleurs suivantes : rouge, orange, jaune, vert, cyan, bleu, violet, rose et blanc.
