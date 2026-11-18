.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _ar_app_control:

17. Contrôle via l'APP
==========================

Dans le projet précédent, nous avons simplement visualisé les images capturées par la caméra et utilisé la fonction de détection IA dans l’application SunFounder Controller.

Dans ce projet, nous allons essayer de contrôler le mouvement et la direction du Zeus Car à l’aide du joystick de l’application. Voyons comment cela fonctionne.

.. note::
    Veuillez installer `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ depuis **l'App Store (iOS)** ou **Google Play (Android)**.


**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Ouvrez le fichier ``17_app_control.ino`` sous le chemin ``zeus-car-main\examples\17_app_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, rebranchez la ESP32-CAM, puis mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    .. image:: img/plug_esp32_cam.jpg

#. Basculez le commutateur de téléversement sur Run (côté droit du schéma) pour lancer la ESP32-CAM.

    .. image:: img/zeus_run.jpg

#. Appuyez sur le bouton de réinitialisation pour relancer le programme de la carte Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Connectez-vous au ``Zeus_Car-XXXXXX``.

    * Recherchez ``Zeus_Car-XXXXXX`` dans les paramètres Wi-Fi de votre téléphone (ou tablette), entrez le mot de passe ``12345678`` et connectez-vous. ``XXXXXX`` correspond aux six derniers caractères de l'adresse MAC de l'ESP32 CAM ; le nom du point d'accès est donc différent sur chaque voiture.

    .. image:: ../img/faq_connect_zeuscar.jpg
        :width: 400

    * Le mode de connexion par défaut est AP mode. Après la connexion, une notification vous informera qu’aucun accès Internet n’est disponible sur ce réseau Wi-Fi. Sélectionnez Continuer la connexion.

    .. image:: img/app_no_internet.png

#. Créez un contrôleur.

    * Pour ajouter un contrôleur dans **SunFounder Controller**, cliquez sur l’icône **+**.

        .. image:: img/app1.png

    * Certains produits disposent de contrôleurs prédéfinis dans la section Preset, mais ici, nous choisissons un modèle Blank et Dual Stick.

        .. image:: img/app_blank.PNG

    * Cliquez sur l’icône + dans la zone J, puis sélectionnez un widget Switch. Vous devrez peut-être faire défiler vers la gauche pour le voir.

        .. image:: img/app_switch_wid.png

        .. note::
            Si vous pensez avoir sélectionné le mauvais widget, vous pouvez cliquer dessus à nouveau et utiliser le bouton Delete pour le supprimer.

            .. image:: img/app_delete.png

    * Cliquez sur l’icône Paramètres en haut à droite pour lui attribuer un nom.

        .. image:: img/app_name_dirft.png

    * Sélectionnez un widget Joystick dans les zones K et Q, attribuez-leur un nom, puis utilisez le bouton |app_save| pour sauvegarder le contrôleur.

    .. image:: img/app_joystick_wid.png

    * Connectez maintenant le Zeus Car à votre appareil via le bouton |app_connect|. Après quelques secondes, ``Zeus_Car(IP)`` apparaîtra, cliquez dessus pour vous connecter.

        .. image:: img/app_connect.png

        .. note::
            Assurez-vous que votre Wi-Fi est connecté à ``Zeus_Car-XXXXXX``, si vous ne voyez pas ce message après un certain temps.


#. Exécutez le contrôleur.

    Une fois le message **"Connected Successfully"** affiché, cliquez sur le bouton |app_run|, l’image de la caméra apparaîtra sur l’application et vous pourrez contrôler votre Zeus Car à l’aide des widgets.

    Les fonctions des trois widgets sont les suivantes :


    **Déplacement dans toutes les directions (K)**

    Le Zeus Car se déplacera dans la direction correspondante lorsque vous faites glisser le widget |app_move_k|.

    .. image:: img/joystick_move.png
        :align: center

    Le véhicule effectue un déplacement à chaque fois que vous faites glisser le widget. Si vous maintenez votre doigt appuyé, la voiture continuera à se déplacer.

    .. image:: img/zeus_move.jpg


    **Activation du Drift (J)**

    Cliquez sur le bouton |app_drift_j| pour activer la fonction de drift.

    * En faisant glisser le widget |app_rotate_q| dans le sens antihoraire, vous verrez le Zeus Car drifter vers la droite. Lorsque vous relâchez, la voiture s’arrête à sa position actuelle.

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * De même, si vous faites glisser le widget |app_rotate_q| dans le sens horaire, le Zeus Car driftera vers la gauche et s’arrêtera à sa position actuelle.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


    **Contrôle de la direction (Q)**

    * Lorsque le bouton |app_drift_j| est activé, le widget |app_rotate_q| est utilisé pour faire drifter le Zeus Car vers la gauche et la droite.

    * Lorsque le widget |app_drift_j| est désactivé, le widget |app_rotate_q| est utilisé pour contrôler l’orientation de la tête du véhicule.

        * En faisant glisser le widget |app_rotate_q| dans le sens antihoraire, la voiture tournera également dans le sens antihoraire. En relâchant le widget, la tête du véhicule reviendra à sa direction initiale.

        .. image:: img/zeus_turn_left.jpg
            :width: 600
            :align: center

        * De la même manière, en faisant glisser le widget |app_rotate_q| dans le sens horaire, la voiture tournera dans le sens horaire et reviendra à sa direction initiale lorsqu’elle sera relâchée.

        .. image:: img/zeus_turn_right.jpg
            :width: 600
            :align: center

