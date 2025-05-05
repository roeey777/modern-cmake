Generate The Documentation
--------------------------

This project uses ``sphinx`` & ``doxygen`` in order to generate it's documentation & hosts them on `Github Pages <https://roeey777.github.io/modern-cmake/>`_.
There are a few steps for generating & hosting documentation.

Automatic generation of documentation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

At first you should verify that you are using the ``modern-cmake`` environment.

.. code-block:: bash

   conda activate modern-cmake

If not installed please refer to the installation page.

Afterwards you should execute the following commands:

.. code-block:: bash

   cmake -S . -B build/docs -Wdev -Werror=dev -DENABLE_DOCS=ON
   cmake --build/docs --target Sphinx
   mkdir -p docs/build
   cp -r build/docs/docs/docs/sphinx/* docs/build/

And now your documentation is built!
You can inspect it as follows:

.. code-block:: bash

   firefox build/docs/docs/docs/sphinx/index.html

Or via:

.. code-block:: bash

   firefox docs/build/index.html


Publishing the Documentation to Github Pages
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The directory ``docs/build/`` needs to be added to git worktree for the branch ``gh-pages``,
which is the default branch `Github <github.com>` uses for the pages feature.
All that is left to do is as follows:

.. code-block:: bash

   cd docs/build/

Now you need to verify that your working on ``gh-pages`` branch, this can be validated as follows:

.. code-block:: bash

   # from docs/build/
   git branch

After this verification we can add all the new documentation.

.. code-block:: bash

   # from repo top directory
   git worktree add -f docs/build gh-pages
   cd docs/build

   # from docs/build/
   git add -A .
   git commit -sm "update documentation"
   git push origin gh-pages

And Your'e Done!


Highly Autonomous Documentation Generation & Publication
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

There is also another way which automates this procedure even further.
All one has to do is simply execute the following (from the top directory of the repository)

.. code-block:: bash

   make docs


This command will generate the documentation using ``sphinx``.
The following command will generate the documentation and publish them onto `Github Pages <https://roeey777.github.io/modern-cmake/>`_.

.. code-block:: bash

   make publish-docs


