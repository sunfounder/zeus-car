.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _ar_grayscale:

13. Niveaux de gris
==============================

Dans ce projet, vous apprendrez à lire et à calibrer le module Omni Grayscale situé sous le Zeus Car.

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``13_hc165_and_grayscale.ino`` sous le chemin ``zeus-car-main\examples\13_hc165_and_grayscale``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c34354c-dd61-4e86-9b99-eccc93e9293f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    .. note::
        Ne débranchez pas le USB à cette étape, car vous devrez vérifier les données du module Omni Grayscale sur votre ordinateur.

#. Ouvrez le moniteur série et assurez-vous que le débit en bauds est réglé sur 115200. Il est recommandé de cliquer sur l’icône **Toggle Autoscroll** pour voir les dernières données imprimées.

    .. image:: img/ar_grayscale.png

    * Retournez la voiture et vous verrez le Moniteur Série afficher ``data: 11111111``.
    * Si vous couvrez l’une des sondes du module avec votre main, vous verrez la valeur correspondante passer à ``0``.
    * Par exemple, si vous couvrez la sonde ``U11``, vous verrez ``data: 01111111``.

#. Calibrer le module Omni Grayscale.

    Comme chaque sol a des niveaux de gris différents, le seuil de gris défini en usine peut ne pas être adapté à votre environnement actuel. Vous devrez donc calibrer ce module avant utilisation. Il est recommandé d’effectuer cette calibration chaque fois que la couleur du sol change considérablement.

    * Placez le Zeus Car sur une surface blanche et tournez le potentiomètre jusqu’à ce que le capteur de gris commence juste à s’illuminer.

        .. image:: img/zeus_line_calibration.jpg

    * Positionnez ensuite les deux capteurs de gris latéraux juste entre la ligne noire et la surface blanche, puis tournez lentement le potentiomètre jusqu’à ce que l’indicateur de signal s’éteigne.

        .. image:: img/zeus_line_calibration1.jpg

    * Déplacez plusieurs fois le capteur entre la ligne noire et la surface blanche pour vous assurer que les lumières du capteur de gris s’éteignent lorsqu’elles sont entre la ligne noire et la surface blanche et qu’elles s’allument lorsqu’elles sont sur la surface blanche, indiquant ainsi que la calibration du module a été réussie.
