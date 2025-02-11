.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

1. Mouvements de base
========================

Dans ce projet, vous apprendrez à faire se déplacer le Zeus Car dans toutes les directions.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Connectez le Zeus Car à votre ordinateur avec le câble USB bleu. Lorsque vous branchez votre carte Arduino, l’ordinateur la reconnaît automatiquement et lui attribue un port COM, que vous pouvez voir dans le Gestionnaire de périphériques.

#. Ouvrez le fichier ``1_basic_move.ino`` sous le chemin ``zeus-car-main\examples\1_basic_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Vous pouvez rapidement sélectionner la carte et le port depuis cet emplacement.

    .. image:: img/ar_board.png
    
    .. note::
        Si COMxx n’apparaît pas, ouvrez le gestionnaire de cartes à gauche et assurez-vous que le cœur "Arduino AVR Boards" est bien installé.

        .. image:: img/ar_other_board.png

#. Cliquez maintenant sur le bouton **Upload** pour téléverser le code sur la carte Arduino. Une notification apparaîtra en bas à droite de votre fenêtre IDE une fois le processus terminé. Bien entendu, en cas d’erreurs lors du téléversement, elles seront également affichées ici.

    .. note::
        * Si vous obtenez le message "Compilation error: SoftPWM.h: No such file or directory", cela signifie que la bibliothèque ``SoftPWM`` n’est pas installée.
        * Veuillez vous référer à :ref:`ar_install_lib` pour installer les bibliothèques requises ``SoftPWM`` et ``IRLremote``.

    .. image:: img/ar_upload.png

#. Démarrez le Zeus Car.

    * Lors de la première utilisation ou si le câble de la batterie a été débranché, le Zeus Car Shield activera son circuit de protection contre la décharge excessive.
    * Vous devez donc brancher le câble Type-C pendant environ 5 secondes.

            .. image:: img/zeus_charge.jpg

    * Si l’indicateur d’alimentation s’allume, cela signifie que la protection a été désactivée. Regardez maintenant les indicateurs de batterie : si les deux sont éteints, continuez à charger la batterie via le câble Type-C.

        .. image:: img/zeus_power.jpg

#. Vous verrez maintenant le Zeus Car se déplacer pendant une seconde dans chaque direction.

    .. image:: img/zeus_move.jpg
        :width: 600

**Comment cela fonctionne-t-il ?**

Ces mouvements sont obtenus grâce à la coopération des 4 roues Mecanum. Par exemple, si les quatre roues avancent ou reculent simultanément, le véhicule se déplacera dans la même direction. Si deux roues avancent et deux reculent, le véhicule effectuera un déplacement latéral ou une rotation vers la gauche ou la droite.

Voici comment ces mouvements sont précisément réalisés.

* Déplacement avant/arrière et latéral.

    .. image:: img/ar_fwlr.jpg
        :width: 600

* Déplacement en diagonale.

    .. image:: img/ar_fblr.jpg
        :width: 600

* Rotation gauche/droite.

    .. image:: img/ar_turn_lr.jpg
        :width: 600

