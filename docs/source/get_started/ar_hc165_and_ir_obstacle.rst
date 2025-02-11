.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

9. Détection infrarouge d'obstacles
========================================

Dans ce projet, vous apprendrez à utiliser les modules d’évitement d’obstacles infrarouges situés de chaque côté du Zeus Car.

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``9_hc165_and_ir_obstacle.ino`` sous le chemin ``zeus-car-main\examples\9_hc165_and_ir_obstacle``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3486be01-6b0e-4e84-86f6-9bdadafa1f48/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    .. note::
        Ne débranchez pas le USB à cette étape, car vous devrez vérifier les données des deux modules d’évitement d’obstacles sur votre ordinateur.

#. Ouvrez le moniteur série et assurez-vous que le débit en bauds est réglé sur 115200, puis observez les données affichées.

   * Si les deux modules d’évitement d’obstacles ne détectent aucun obstacle, le moniteur série affichera ``0, 0``.
   * Si vous placez votre main devant l’un des modules, il affichera ``1, 0`` ou ``0, 1``.

    .. image:: img/ar_serial.png

#. Calibrer le module d’évitement d’obstacles infrarouge.

    * Commencez par ajuster le module d’évitement d’obstacles droit. Pendant le transport, des chocs peuvent provoquer une inclinaison de l’émetteur et du récepteur sur le module infrarouge. Il est donc nécessaire de les redresser manuellement.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Placez un obstacle à environ 15 cm du module d’évitement d’obstacles infrarouge.
    * Sur le module, il y a deux potentiomètres, l'un permettant d'ajuster la puissance d'émission et l'autre la fréquence d’émission. En ajustant ces deux potentiomètres, vous pouvez modifier la distance de détection.
    * Ajustez un potentiomètre, et si à 15 cm, le voyant du module s’allume, l’ajustement est réussi ; sinon, ajustez l’autre potentiomètre.

        .. image:: img/zeus_ir_avoid.jpg

    * Répétez la même procédure pour calibrer l’autre module d’évitement d’obstacles.
