.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

15. Suivi de ligne centré sur le champ
==========================================

Dans ce projet, nous explorerons un mode de suivi de ligne différent : le déplacement avec boussole.

Le résultat expérimental est quasiment identique à :ref:`ar_line_track`, cependant, la tête du Zeus Car reste toujours orientée dans une direction fixe, tandis que dans le projet précédent, elle changeait avec la direction de la ligne.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/> 

**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``15_line_track_field_centric.ino`` sous le chemin ``zeus-car-main\examples\15_line_track_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/6b6734cb-38c9-4a5b-81b7-3decced20326/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

#. Ensuite, votre Zeus Car suivra la ligne tout en gardant sa tête orientée dans une seule direction. Si votre Zeus Car sort de la ligne, cela peut signifier que vous devez recalibrer le :ref:`ar_grayscale`, ou réduire sa vitesse.
