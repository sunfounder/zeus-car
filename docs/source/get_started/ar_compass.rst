.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

7. Boussole
=============

Dans ce projet, le Zeus Car se transformera en boussole. Vous devrez définir une direction cible, et peu importe comment vous le tournez, il s’orientera toujours vers cette direction.

.. note::
    Si des fils électriques sont présents à proximité du Zeus Car, le champ électromagnétique peut interférer avec le fonctionnement du module qmc6310, modifiant ainsi la direction de l’orientation du véhicule.

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Ouvrez le fichier ``7_compass.ino`` sous le chemin ``zeus-car-main\examples\7_compass``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/672af146-1b45-46f6-b1d9-8ad9ecdcf8c0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

#. Commençons par calibrer le module qmc6310.

    * Placez la voiture sur une surface plane (assurez-vous qu’elle soit éloignée d’un sol contenant des câbles électriques).
    * Appuyez sur |ir_mute| et la voiture commencera à tourner sur place.
    * Elle s’arrêtera automatiquement une fois que le champ magnétique à cet endroit aura été entièrement enregistré.
    * Si elle ne s’arrête pas après plus de 2 minutes, vous pouvez appuyer sur |ir_power| pour arrêter la calibration, puis recommencer ailleurs.


#. Orientez le véhicule dans la direction souhaitée et appuyez sur |ir_play|. Désormais, quelle que soit la manière dont vous tournez la voiture, elle reviendra lentement vers la direction définie.

#. Les champs magnétiques varient entre le sol et une table, il est donc nécessaire de recalibrer la boussole en fonction de la surface sur laquelle se trouve la voiture.
