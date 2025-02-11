.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

Module d'Évitement d'Obstacles Infrarouge
===========================================

.. image:: img/ir_avoid.png

* **GND** : Entrée de masse
* **+** : Alimentation en courant continu de 3.3V à 5V
* **Out** : Broche de sortie du signal, par défaut à l'état haut et passe à l'état bas lorsqu'un obstacle est détecté
* **EN** : Broche d’activation du module. Lorsqu’elle est à un niveau bas, le module fonctionne. Elle est connectée à GND par défaut via un cavalier.

Ce module d’évitement d'obstacles infrarouge est un capteur classique utilisant une paire d'émetteur et de récepteur infrarouges. L’émetteur émet un faisceau infrarouge, et lorsqu’un obstacle est présent dans la direction de détection, la lumière infrarouge est réfléchie et reçue par le récepteur. À ce moment-là, l’indicateur s’allume. Après traitement du signal, une sortie de niveau bas est générée.

La distance de détection est comprise entre 2 et 40 cm et le module dispose d’une excellente capacité anti-interférence. La réflectivité des objets varie en fonction de leur couleur : plus l'objet est foncé, plus la distance de détection est réduite. Par exemple, contre un mur blanc, la plage de détection est d’environ 2 à 30 cm.

Lorsque la broche EN est à un niveau bas, le module est actif. Avec le cavalier en place, la broche EN est reliée à GND et le module fonctionne en permanence. Si vous souhaitez contrôler la broche EN par code, il est nécessaire de retirer le cavalier.

.. image:: img/ir_avoid_cap.png

**Ajuster la distance de détection**

En raison des variations de luminosité ambiante, la distance de détection définie en usine peut ne pas convenir. Il est donc nécessaire de l’ajuster avant utilisation.

Le module est équipé de deux potentiomètres : l’un permet d’ajuster la puissance d’émission et l’autre la fréquence d’émission. En ajustant ces deux paramètres, vous pouvez régler la portée de détection effective.

Placez un obstacle blanc à la distance souhaitée devant le module, puis ajustez un des potentiomètres jusqu'à ce que le voyant du module s’allume juste à cette distance. Déplacez ensuite l’obstacle plusieurs fois pour vérifier que le voyant s'allume au bon moment.

Si l’indicateur ne s’allume pas ou reste allumé en continu à la distance requise, ajustez le second potentiomètre pour affiner le réglage.

.. image:: ../get_started/img/zeus_ir_avoid.jpg

**Caractéristiques**

* Tension de fonctionnement : 3.3V à 5V
* Sortie : numérique (on/off)
* Seuil de détection : réglable via deux potentiomètres
* Plage de détection : 2 à 40 cm
* Réglage R5 : fréquence d’émission (38 kHz, déjà optimisée)
* Réglage R6 : ajustement du cycle de service de la LED IR (déjà optimisé)
* Température de fonctionnement : -10 °C à +50 °C
* Angle de détection effectif : 35°
* Interface I/O : 4 fils (- / + / S / EN)
* Dimensions : 45 x 16 x 10 mm
* Poids : 9 g
