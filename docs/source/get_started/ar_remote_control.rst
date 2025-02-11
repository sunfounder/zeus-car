.. note::  

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, d’Arduino et de l’ESP32 avec d’autres passionnés.  

    **Pourquoi nous rejoindre ?**  

    - **Support d’experts** : Obtenez de l’aide pour résoudre vos problèmes après-vente et relevez vos défis techniques grâce à notre communauté et notre équipe.  
    - **Apprenez & partagez** : Échangez des conseils et tutoriels pour perfectionner vos compétences.  
    - **Aperçus exclusifs** : Profitez d’un accès anticipé aux annonces de nouveaux produits et à des avant-premières exclusives.  
    - **Réductions spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.  
    - **Promotions et cadeaux festifs** : Participez à des jeux-concours et à des offres spéciales à l’occasion des fêtes.  

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !  

5. Télécommande  
======================

Dans ce projet, vous apprendrez à contrôler la Zeus Car à l’aide d’une télécommande.  

.. raw:: html  

   <video loop autoplay muted style = "max-width:80%">  
      <source src="../_static/video/ir_control.mp4"  type="video/mp4">  
      Your browser does not support the video tag.
   </video>  

.. raw:: html  

    <br/> <br/>  

**Comment procéder ?**  

#. L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Ainsi, lors du téléversement du code, il est nécessaire de déconnecter l'ESP32-CAM pour éviter tout conflit ou problème potentiel.  

    .. image:: img/unplug_cam.png  
        :width: 400  
        :align: center  

#. Ouvrez le fichier ``5_remote_control.ino`` situé sous le chemin ``zeus-car-main\examples\5_remote_control``.  

    .. raw:: html  

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>  

#. Une fois le code téléversé avec succès, mettez l’interrupteur d’alimentation sur ON pour démarrer la Zeus Car.  

#. Utilisez ensuite les touches 1 à 9 de la télécommande pour contrôler la voiture dans 8 directions différentes.  

    .. image:: img/ar_remote_control.png  
        :width: 600  
        :align: center  

#. Après avoir appuyé sur une touche, la Zeus Car continuera de se déplacer jusqu’à ce que vous appuyiez sur |ir_power| ou sur la touche 5.  

    .. image:: img/zeus_move.jpg  
        :width: 600  
        :align: center  

#. Si vous appuyez une fois sur |ir_return|, la voiture tournera dans le sens antihoraire en prenant son propre axe comme centre, et elle s’arrêtera uniquement si vous appuyez sur |ir_power| ou sur la touche 5.  

    .. image:: img/zeus_turn_left.jpg  
        :width: 600  
        :align: center  

#. De la même manière, en appuyant une fois sur |ir_usd|, la voiture tournera dans le sens horaire et s’arrêtera uniquement lorsque vous appuierez sur |ir_power| ou sur la touche 5.  

    .. image:: img/zeus_turn_right.jpg  
        :width: 600  
        :align: center  