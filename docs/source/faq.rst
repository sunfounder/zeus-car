.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

FAQ
================

Comment changer de canal Wi-Fi ?
-------------------------------------

La bande Wi-Fi 2,4 GHz dispose de 13 canaux, et l’ESP32 prend en charge les canaux 1 à 11. D’autres appareils utilisant le même canal peuvent causer des interférences et entraîner des problèmes de connexion. Pour atténuer ce problème, il est possible de modifier le canal. Par défaut, le canal est défini sur 1. Lors du changement de canal, il est recommandé d’en sauter 1 à 2 à la fois. Par exemple, si le canal actuel est 1, essayez d’abord le canal 3, puis, si le signal est toujours faible, passez au canal 5.

.. note::

   La modification du canal nécessite une version du firmware ESP32 CAM 1.4.1 ou supérieure. Consultez :ref:`update_firmware` pour plus de détails.

#. Laissez l’ESP32 CAM inséré dans l’adaptateur, puis mettez sous tension la Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Activez l’**ESP32 CAM** en basculant le mode switch en position **Run**, puis appuyez sur le **Reset** pour redémarrer la carte R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Recherchez ``Zeus Car`` dans la liste des réseaux Wi-Fi disponibles sur votre appareil mobile (tablette ou smartphone), entrez le mot de passe ``12345678``, puis connectez-vous.

   .. note::

        * La connexion actuelle est établie sur le hotspot Zeus Car, donc sans accès Internet. Si une invite vous propose de changer de réseau, sélectionnez "Rester connecté".

   .. image:: img/app_wlan.png
        :width: 500

#. Ouvrez un navigateur web sur votre appareil mobile et accédez à ``http://192.168.4.1`` pour afficher la page de mise à jour OTA de l’ESP32 CAM.

   .. image:: img/faq_cam_ota_141.jpg
      :width: 400

#. Dans la section **Wi-Fi AP Channel**, sélectionnez un nouveau canal.

   * Le canal par défaut est 1. Lors de la sélection d’un nouveau canal, sautez 1 à 2 canaux à la fois (ex. : passez de 1 à 3, puis si nécessaire à 5).
   * Cliquez sur le bouton **Confirm** pour enregistrer les modifications.

   .. image:: img/faq_cam_ota_channel.png
      :width: 400

#. Une fenêtre de confirmation apparaîtra, demandant de redémarrer l’appareil. Cliquez sur **Confirm**.

   .. image:: img/faq_cam_ota_reset.jpg
      :width: 400
   
#. Appuyez sur le **Reset** pour redémarrer l’appareil. La Zeus Car est maintenant prête à fonctionner normalement.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _update_firmware:

Comment mettre à jour le firmware de l’ESP32 CAM ?
-----------------------------------------------------

Suivez ces étapes détaillées pour mettre à jour le firmware de votre ESP32 CAM :

#. Laissez l’ESP32 CAM inséré dans l’adaptateur, puis allumez la Zeus Car.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Activez l’ESP32 CAM en basculant le mode switch en position **Run**, puis appuyez sur le **Reset** pour redémarrer la carte R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Recherchez ``Zeus Car`` dans la liste des réseaux Wi-Fi disponibles sur votre appareil mobile (tablette ou smartphone), entrez le mot de passe ``12345678``, puis connectez-vous.

   .. note::

      * La connexion actuelle est établie sur le hotspot Zeus Car, donc sans accès Internet. Si une invite vous propose de changer de réseau, sélectionnez "Rester connecté".

   .. image:: img/app_wlan.png
        :width: 500

#. Cliquez sur le lien ci-dessous pour télécharger le fichier firmware  ``ai-camera-firmware-v1.4.1-ota.bin`` et enregistrez-le sur votre appareil mobile.

   * :download:`Firmware ESP32 CAM <https://github.com/sunfounder/ai-camera-firmware/releases/download/1.4.1/ai-camera-firmware-v1.4.1-ota.bin>`

#. Ouvrez un navigateur web sur votre appareil mobile et accédez à ``http://192.168.4.1`` pour afficher la page de mise à jour OTA de l’ESP32 CAM.

   .. image:: img/faq_cam_ota.jpg
      :width: 400

#. Sur la page OTA, cliquez sur le bouton pour sélectionner le fichier firmware.

   .. image:: img/faq_cam_ota_choose.png
      :width: 400

#. Sélectionnez le fichier ``ai-camera-firmware-v1.4.1-ota.bin`` précédemment téléchargé sur votre appareil, puis cliquez sur **OK**.

   .. image:: img/faq_cam_ota_file.png
      :width: 400

#. Cliquez sur le bouton **Update** pour lancer la mise à jour du firmware.

   .. image:: img/faq_cam_ota_update.png
      :width: 400
   
#. Patientez jusqu’à la fin de la mise à jour. Une fois la mise à jour terminée, la version affichée doit être ``1.4.1``, indiquant une mise à jour réussie.

   .. image:: img/faq_cam_ota_finish.png
      :width: 400
   
#. Après la mise à jour, vous pouvez fermer le navigateur web. Appuyez sur le **Reset** pour redémarrer l’appareil. L’ESP32 CAM est maintenant prête à fonctionner normalement.

   .. image:: img/zeus_run123.jpg
      :width: 600

.. _upload_zeus_code:

Comment téléverser le code ``zeus-car.ino`` ? 
-----------------------------------------------

Par défaut, la carte Uno R3 de la Zeus Car est préchargée avec le firmware nécessaire, ce qui permet de la contrôler via l'application mobile. Si votre carte R3 a été écrasée par un autre code et que vous souhaitez revenir au firmware d’origine pour suivre le processus :ref:`quick_start`, suivez ces étapes pour réinstaller le code sur votre carte R3 :

#. Utilisez un câble USB pour connecter la carte Arduino à votre ordinateur. L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Pour éviter les conflits lors du téléversement du code, commencez par déconnecter l’ESP32-CAM.

   .. image:: img/unplug_cam.png
        :width: 400

#. Téléchargez le firmware requis depuis le lien ci-dessous : 
       
   * :download:`Fichier du firmware R3 Board <https://github.com/sunfounder/zeus-car/releases/download/1.4.5/zeus-car-1.4.5.zip>`

#. Extrayez le fichier ZIP téléchargé, puis double-cliquez sur ``update-arduino-firmware.bat`` pour l’exécuter.

   .. image:: img/faq_firmware_file.png

#. Tapez le numéro correspondant à votre Zeus Car (ex. : ``1``), puis appuyez sur **Enter** pour démarrer la mise à jour.

   .. note::

     * Si le port COM correct n’apparaît pas ou si vous ne savez pas lequel choisir, déconnectez les autres périphériques USB de votre ordinateur, en laissant uniquement la Zeus Car branchée.  
     * Si vous rencontrez une erreur comme ``avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX``, assurez-vous d’avoir déconnecté l’ESP32-CAM avant de continuer.

   .. image:: img/faq_firmware_port.png

#. Après quelques instants, le nouveau code sera correctement téléversé sur la carte Uno R3 de la Zeus Car. Si l’opération échoue après plusieurs tentatives, essayez d’exécuter ``update-arduino-firmware-with-bootloader.bat``.

   .. image:: img/faq_firmware_finish.png

.. _ap_to_sta:

Comment contrôler la Zeus Car via le Wi-Fi domestique ?
----------------------------------------------------------

Par défaut, le Uno R3 est préchargé avec un code en mode APP, ce qui signifie que la Zeus Car émettra un hotspot auquel vous pouvez vous connecter avec votre mobile pour la contrôler via l’**application SunFounder Controller**.

Si vous souhaitez contrôler la Zeus Car via le Wi-Fi de votre domicile, suivez ces étapes pour modifier et téléverser le code sur la carte Uno :

#. Téléchargez les fichiers requis depuis le lien suivant :

   * :download:`Code de la Zeus Car <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

#. Consultez le guide d’installation : :ref:`install_arduino_ide`.

#. Utilisez le **Library Manager** pour installer les bibliothèques ``SoftPWM`` et ``SunFounder AI Camera``. Pour des instructions détaillées, consultez :ref:`ar_install_lib`.

#. Accédez au répertoire ``zeus-car-main\zeus-car`` et ouvrez le fichier ``zeus-car.ino``.

   .. image:: img/faq_galaxy_code.png
      :width: 600

#. Commentez les lignes du mode AP, décommentez les lignes du mode STA, et remplacez ``SSID`` et ``PASSWORD`` par les identifiants de votre réseau Wi-Fi domestique.

   .. code-block:: arduino

      /** Configure Wifi mode, SSID, password*/
      // #define WIFI_MODE WIFI_MODE_AP
      // #define SSID "Zeus_Car"
      // #define PASSWORD "12345678"

      #define WIFI_MODE WIFI_MODE_STA
      #define SSID "xxxxxxxxxx"
      #define PASSWORD "xxxxxxxxxx"

#. Utilisez un câble USB pour connecter la carte Arduino à votre ordinateur. L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX et TX, il est donc nécessaire de déconnecter l’ESP32-CAM avant de téléverser le code pour éviter tout conflit.

   .. image:: img/unplug_cam.png
        :width: 400

#. Cliquez sur le **Upload** dans l’**Arduino IDE** pour téléverser le code modifié sur la carte Uno.

   .. image:: img/faq_galaxy_upload.png
      :width: 600

#. Une fois le téléversement terminé, rebranchez l’ESP32-CAM et mettez l’interrupteur Power sur ON pour allumer la Zeus Car.

   .. image:: img/plug_esp32_cam.jpg

#. Activez l’**ESP32-CAM** en basculant le mode switch en position **Run**, puis appuyez sur le **Reset** pour redémarrer la carte R3.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Vérifiez que votre appareil mobile (tablette ou smartphone) est bien connecté à votre réseau Wi-Fi domestique.

   .. image:: img/faq_connect_wifi.jpg
        :width: 400
        :align: center

#. Ouvrez l’application SunFounder Controller, appuyez sur l’icône "+" pour créer un nouveau contrôleur, sélectionnez le préréglage "Zeus Car", entrez un nom ou appuyez sur "Confirmer".

   .. image:: img/app_preset.jpg
        :width: 600

#. L’application recherchera automatiquement la Zeus Car. Après quelques instants, un message s’affichera indiquant "Connexion réussie".

   .. image:: img/app_edit.jpg
        :width: 600
    
#. Maintenant, appuyez sur le bouton |app_run| pour afficher le flux vidéo en direct de la caméra et contrôler le robot à l’aide des widgets fournis.

   .. image:: img/app_run123.png
        :width: 600

Comment inverser l'affichage de la caméra ?  
----------------------------------------------

Si l’image de la caméra apparaît à l’envers dans l’application SunFounder Controller, vous pouvez facilement la corriger en suivant ces étapes :  

1. Appuyez sur le bouton |app_edit| en haut à droite.  

   .. image:: img/faq_edit.png  
        :width: 500 

2. Cliquez sur le bouton caméra pour ouvrir une fenêtre contextuelle. Activez l'option Inversé en basculant l’interrupteur.  

   .. image:: img/faq_inverted.png  
        :width: 500  

3. Enregistrez vos paramètres.  

   .. image:: img/faq_save.png  
        :width: 500 

4. Retournez à l’interface de contrôle et appuyez sur le bouton |app_run|.  

   .. note::  

        Parfois, l’image de la caméra peut ne pas s’afficher immédiatement. Si cela se produit, mettez l’application en pause, puis cliquez à nouveau sur le bouton Exécuter.  

   .. image:: img/faq_run.png  
        :width: 500 

Erreur de compilation : SoftPWM.h: No such file or directory ?  
------------------------------------------------------------------
Si vous obtenez le message "Compilation error: SoftPWM.h: No such file or directory", cela signifie que la bibliothèque ``SoftPWM`` n’est pas installée.

Veuillez consulter :ref:`ar_install_lib` pour installer les bibliothèques nécessaires.


Erreur avrdude: stk500_getsync() attempt 10 of 10: not in sync: resp=0x6e ?  
----------------------------------------------------------------------------

Si le message d'erreur suivant s'affiche à plusieurs reprises après avoir cliqué sur le bouton Téléverser, alors que la carte et le port sont correctement sélectionnés :

.. code-block::

    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 2 of 10: not in sync: resp=0x00
    avrdude: stk500_recv(): programmer is not responding
    avrdude: stk500_getsync() attempt 3 of 10: not in sync: resp=0x00

Dans ce cas, assurez-vous que l'ESP32 CAM est bien débranché.

L’**ESP32-CAM** et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lors du téléversement du code, il est indispensable de déconnecter d'abord l'ESP32-CAM afin d'éviter tout conflit ou problème potentiel.

.. image:: img/unplug_cam.png
    :width: 400
    :align: center


.. _stt_android:

Comment utiliser la fonctionnalité STT sur un appareil Android ?  
--------------------------------------------------------------------

La fonctionnalité STT (Speech-to-Text) nécessite que l’appareil Android soit connecté à Internet et dispose du service Google installé.

Suivez ces étapes pour l’activer :

#. Modifiez le mode AP dans le fichier ``Zeus_Car.ino`` pour passer en mode STA.

    * Ouvrez le fichier ``Zeus_Car.ino`` situé dans le répertoire ``zeus-car-main/Zeus_Car``.  
    * Commentez les lignes relatives au mode AP, décommentez celles du mode STA, et remplacez ``SSID`` et ``PASSWORD`` par les informations de connexion de votre Wi-Fi domestique.

        .. code-block:: arduino

            /** Configure Wifi mode, SSID, password*/
            // #define WIFI_MODE WIFI_MODE_AP
            // #define SSID "Zeus_Car"
            // #define PASSWORD "12345678"

            #define WIFI_MODE WIFI_MODE_STA
            #define SSID "xxxxxxxxxx"
            #define PASSWORD "xxxxxxxxxx"

    * Enregistrez ce fichier, sélectionnez la bonne carte (Arduino Uno) et le bon port, puis cliquez sur le bouton Téléverser pour envoyer le code à la carte R3.

#. Recherchez ``google`` sur Google Play, trouvez l’application illustrée ci-dessous et installez-la.

    .. image:: img/google_voice.png

#. Connectez votre appareil mobile au même réseau Wi-Fi que celui configuré dans le code.

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

#. Ouvrez le contrôleur précédemment créé dans l’application SunFounder Controller et connectez-le à ``Zeus_Car`` via le bouton |app_connect|.

    .. image:: img/app_connect.png
        :width: 500
        :align: center

#. Appuyez longuement sur le  |app_speech_m| après avoir cliqué sur le bouton |app_run|. Une invite apparaîtra indiquant que l’application écoute. Prononcez l’une des commandes suivantes pour déplacer la voiture :

    * ``stop`` : Arrête tous les mouvements de la voiture.  
    * ``pause`` : Fonction similaire à Stop, mais si l’orientation de la voiture ne correspond plus à sa position initiale, elle ajustera lentement sa direction.  
    * ``forward`` : Avancer  
    * ``backward`` : Reculer  
    * ``left forward`` : Avancer vers la gauche  
    * ``left backward`` : Reculer vers la gauche  
    * ``right forward`` : Avancer vers la droite  
    * ``right backward`` : Reculer vers la droite  
    * ``move left`` : Se déplacer latéralement vers la gauche  
    * ``move right`` : Se déplacer latéralement vers la droite  
