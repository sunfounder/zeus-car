.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

8. Déplacement à Référence Fixe
=======================================

Ce projet repose sur le précédent en intégrant la fonction boussole au mouvement du Zeus Car. 
Lorsque vous contrôlez le déplacement du Zeus Car avec la télécommande, s’il est dévié par une force extérieure (par exemple, un coup de pied d’un chien), il se réalignera automatiquement sur sa direction initiale.


**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Ouvrez le fichier ``8_move_field_centric.ino`` sous le chemin ``zeus-car-main\examples\8_move_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

#. Utilisez ensuite les touches numérotées de 1 à 9 sur la télécommande pour diriger le véhicule dans 8 directions. Une fois une touche pressée, le Zeus Car continuera à avancer jusqu'à ce que vous appuyiez sur |ir_power| ou sur la touche 5.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. Lorsque vous appuyez une fois sur |ir_return|, le véhicule effectuera une rotation antihoraire sur lui-même et s’arrêtera uniquement si vous appuyez sur |ir_power| ou sur la touche 5.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. De la même manière, appuyer sur |ir_usd| entraînera une rotation horaire du Zeus Car, qui s’arrêtera lorsque vous appuierez sur |ir_power| ou sur la touche 5.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center

#. Appuyez sur la touche |ir_minus|, et le véhicule effectuera une dérive vers la gauche.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. Appuyez sur la touche **|ir_plus|**, et le véhicule effectuera une dérive vers la droite.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center

.. note::

    * Si le Zeus Car ne se déplace pas correctement, cela peut signifier que la boussole n'est pas correctement calibrée. Vous devez appuyer sur |ir_mute| pour la calibrer.
    * Si vous soulevez le véhicule du sol et le placez sur une table, le champ magnétique changera, et vous devrez le recalibrer.
