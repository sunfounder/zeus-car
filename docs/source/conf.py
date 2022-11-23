# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
import time

# -- Project information -----------------------------------------------------

project = 'SunFounder Zeus Robot Car Kit for Arduino'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# The full version, including alpha/beta/rc tags
release = '1.0'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['sphinx.ext.autosectionlabel']

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

from recommonmark.parser import CommonMarkParser
source_parsers = {
    '.md': CommonMarkParser,
}
source_suffix = ['.rst', '.md']

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]


rst_epilog = """

.. |ir_power| image:: /get_started/img/remote/ir_power.png
    :width: 40

.. |ir_mute| image:: /get_started/img/remote/ir_mute.png
    :width: 40

.. |ir_play| image:: /get_started/img/remote/ir_play.png
    :width: 40

.. |ir_backward| image:: /get_started/img/remote/ir_backward.png
    :width: 40

.. |ir_forward| image:: /get_started/img/remote/ir_forward.png
    :width: 40

.. |ir_minus| image:: /get_started/img/remote/ir_minus.png
    :width: 40

.. |ir_plus| image:: /get_started/img/remote/ir_plus.png
    :width: 40

.. |ir_0| image:: /get_started/img/remote/ir_0.png
    :width: 40

.. |ir_return| image:: /get_started/img/remote/ir_return.png
    :width: 40

.. |ir_usd| image:: /get_started/img/remote/ir_usd.png
    :width: 40

.. |app_connect| image:: /get_started/img/app/app_connect.jpg
    :width: 20

.. |app_save| image:: /get_started/img/app/app_save.jpg
    :width: 20

.. |app_run| image:: /get_started/img/app/app_run.png
    :width: 20

.. |app_avoid_p| image:: /get_started/img/app/app_avoid_p.png
    :width: 100
    
.. |app_cali_e| image:: /get_started/img/app/app_cali_e.png
    :width: 100
    
.. |app_drift_j| image:: /get_started/img/app/app_drift_j.png
    :width: 100

.. |app_follow_o| image:: /get_started/img/app/app_follow_o.png
    :width: 100

.. |app_heading_i| image:: /get_started/img/app/app_heading_i.png
    :width: 100

.. |app_line_n| image:: /get_started/img/app/app_line_n.png
    :width: 100

.. |app_move_k| image:: /get_started/img/app/app_move_k.png
    :width: 100

.. |app_rotate_q| image:: /get_started/img/app/app_rotate_q.png
    :width: 100

.. |app_speech_m| image:: /get_started/img/app/app_speech_m.png
    :width: 100

.. |app_stop_f| image:: /get_started/img/app/app_stop_f.png
    :width: 100

.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Arduino IDE 2.0.0 Page</a>


.. |link_install_library| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v1/tutorials/installing-librariese" target="_blank">Installing Libraries</a>




"""