.. note::  

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur du Raspberry Pi, de l'Arduino et de l'ESP32 avec d'autres passionnés.  

    **Pourquoi nous rejoindre ?**  

    - **Support d'experts** : Obtenez de l'aide pour résoudre vos problèmes après-vente et défis techniques grâce à notre communauté et notre équipe.  
    - **Apprenez & partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.  
    - **Aperçus exclusifs** : Profitez d’un accès anticipé aux annonces de nouveaux produits et à des avant-premières.  
    - **Réductions spéciales** : Bénéficiez d'offres exclusives sur nos derniers produits.  
    - **Promotions festives et cadeaux** : Participez à nos jeux concours et offres spéciales pour les fêtes.  

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !  

2. Déplacement omnidirectionnel  
========================================
Dans ce projet, vous apprendrez à déplacer la Zeus Car selon les angles suivants : 0°, 45°, 90°, 135°, 180°, 225°, 270° et 315°.  

Si l'on ignore les frictions au sol et les tolérances structurelles, la trajectoire suivie devrait être un octogone, ramenant finalement la voiture à son point de départ.  

**Comment procéder ?**  

#. L'ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Ainsi, lors du téléversement du code, il est nécessaire de déconnecter l'ESP32-CAM pour éviter tout conflit ou problème potentiel.  

    .. image:: img/unplug_cam.png  
        :width: 400  
        :align: center  

#. Ouvrez le fichier ``2_omni_move.ino`` situé sous le chemin ``zeus-car-main\examples\2_omni_move``.  

    .. raw:: html  

        <iframe src=https://create.arduino.cc/editor/sunfounder01/2425f280-5bd4-4e49-bb2e-220d1f4f867b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>  

#. Sélectionnez la carte et le port corrects, puis cliquez sur le bouton **Upload**.  

    .. note::  
        * Si vous obtenez l'erreur **"Compilation error: SoftPWM.h: No such file or directory"**, cela signifie que la bibliothèque ``SoftPWM`` n'est pas installée.  
        * Veuillez consulter :ref: `ar_install_lib` pour installer les deux bibliothèques nécessaires : ``SoftPWM`` et ``IRLremote``.  

    .. image:: img/ar_board_upload.png  

#. Basculez l'interrupteur d'alimentation sur ON pour démarrer la Zeus Car.  

    .. image:: img/zeus_power.jpg  

#. À ce stade, la Zeus Car se déplacera selon les angles 0°, 45°, 90°, 135°, 180°, 225°, 270° et 315°.  


**Comment ça fonctionne ?**  

Le déplacement de la Zeus Car est principalement contrôlé par cette fonction :  

.. code-block::  

    void carMove(int16_t angle, int8_t power)  

* ``angle`` : La direction dans laquelle vous souhaitez déplacer la voiture. L'avant du véhicule correspond à 0°, et l'angle augmente dans le sens antihoraire.  
* ``power`` : La puissance de déplacement, comprise entre -100 % et 100 %. Lorsque ``power`` est positif, la voiture avance ; lorsqu'il est négatif, elle recule.  
