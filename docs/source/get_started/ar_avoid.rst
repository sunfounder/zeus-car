.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

11. Évitement d'obstacles
================================

Dans ce projet, le Zeus Car avancera automatiquement, et deux modules d’évitement d’obstacles ainsi qu’un module à ultrasons l’empêcheront de percuter des obstacles.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``11_obstacle_avoid.ino`` sous le chemin ``zeus-car-main\examples\11_obstacle_avoid``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    * Le Zeus Car avancera en ligne droite.
    * Le module à ultrasons détecte les obstacles devant lui. Si un obstacle est détecté, le véhicule tournera à gauche.
    * Lorsque le module d’évitement gauche détecte un obstacle, la voiture tourne à droite. Lorsque le module d’évitement droit détecte un obstacle, la voiture tourne à gauche.

.. note::
    Avant utilisation, vous devez régler la distance de détection des deux modules d’évitement d’obstacles à 15 cm, les étapes sont les suivantes :

    * Commencez par ajuster le module d’évitement droit. Lors du transport, des chocs peuvent incliner l’émetteur et le récepteur du module infrarouge. Vous devez donc les redresser manuellement.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Placez un obstacle à environ 15 cm du module d’évitement infrarouge.
    * Sur le module, il y a deux potentiomètres : l’un pour ajuster la puissance d’émission, et l’autre pour régler la fréquence d’émission. En ajustant ces deux potentiomètres, vous pouvez modifier la distance de détection.
    * Ajustez un potentiomètre et si, à 15 cm, le voyant du module s’allume, l’ajustement est réussi ; sinon, ajustez l’autre potentiomètre.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibrez l’autre module d’évitement d’obstacles de la même manière.
