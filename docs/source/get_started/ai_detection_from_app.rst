.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

16. Détection IA via l'application
=====================================

Dans ce projet, nous allons utiliser l'application - SunFounder Controller pour visionner un flux vidéo en temps réel et exploiter les fonctionnalités de détection IA sur votre appareil mobile, telles que la reconnaissance faciale et la détection de posture.

SunFounder Controller est une application qui permet aux utilisateurs de personnaliser un contrôleur pour piloter leur robot ou l’utiliser comme plateforme IoT. Elle intègre 11 types de widgets d'affichage et de contrôle, comme Button, Joystick, Gauge et Radar. La page de contrôle comprend 17 zones, de A à Q, où vous pouvez placer différents widgets pour créer votre propre interface personnalisée.

Voyons maintenant comment utiliser l’application de manière simple.

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, il est nécessaire de déconnecter d'abord la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``16_ai_detection_from_app.ino`` situé dans ``zeus-car-main\examples\16_ai_detection_from_app``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/c14c46e7-2e43-4b31-b7e6-b7718e501e96/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, reconnectez la ESP32-CAM et activez l’interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Basculez le commutateur de téléversement en position Run (côté droit du schéma) pour lancer la ESP32-CAM.

    .. image:: img/zeus_run.jpg

#. Appuyez sur le bouton de réinitialisation pour relancer le programme de la carte Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Téléchargez et installez l’application `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ depuis **l’App Store (iOS)** ou **Google Play (Android)** sur votre appareil mobile.


#. Connectez-vous au réseau WLAN ``Zeus_Car``.

    * Trouvez le réseau ``Zeus_Car`` dans les paramètres Wi-Fi de votre smartphone (ou tablette), saisissez le mot de passe ``12345678``, puis connectez-vous.

    .. image:: img/app_wlan.png

    * Le mode de connexion par défaut est le mode AP. Après la connexion, une notification vous informera que ce réseau Wi-Fi ne fournit pas d’accès à Internet. Sélectionnez Continuer la connexion.

    .. image:: img/app_no_internet.png

#. Ouvrez l’application et créez un contrôleur.

    * Pour ajouter un contrôleur dans SunFounder Controller, cliquez sur l’icône **+**.

        .. image:: img/app1.png

    * Sélectionnez le modèle **Blank** ou **Dual Stick**, puis attribuez-lui un nom.

        .. image:: img/view_app1.jpg

    * Une fois dans l’interface de contrôle, cliquez sur l’icône |app_camera| pour activer la fonctionnalité détection IA. Vous y trouverez les options détection faciale et détection de posture.

        .. image:: img/view_app6.jpg

    * Enregistrez vos paramètres en cliquant sur le bouton |app_save|. Si aucun widget n’a été sélectionné, l’écran restera noir.

        .. image:: img/view_app3.jpg

    * L’étape suivante consiste à connecter le Zeus Car à votre appareil via le bouton |app_connect|. Après quelques secondes, ``Zeus_Car(IP)`` apparaîtra. Cliquez dessus pour établir la connexion.

        .. image:: img/view_app4.jpg

        .. note::
            Assurez-vous que votre appareil est bien connecté au **Wi-Fi Zeus_Car** si vous ne voyez pas le message ci-dessus après un certain temps.

#. Démarrez le contrôleur.

    Une fois le message "Connexion réussie" affiché, cliquez sur le bouton |app_run|. Le flux vidéo de la caméra s’affichera alors dans l’application.

    Si la détection faciale est activée, tout visage apparaissant à l’écran sera encadré.

    .. image:: img/view_app7.jpg

    Si la détection de posture est activée, la posture sera analysée et affichée.

    .. image:: img/view_app8.jpg

    .. note::

        Si vous souhaitez passer à un autre mode de détection IA, cliquez sur l’icône |app_edit| et répétez les étapes ci-dessus.
