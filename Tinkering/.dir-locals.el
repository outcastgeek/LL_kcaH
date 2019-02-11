;; https://projectile.readthedocs.io/en/latest/configuration/
;; Projectile Configuration
((nil . ((eval . (setq projectile-project-root
                       (locate-dominating-file buffer-file-name
                                               ".dir-locals.el")))
         (eval . (setq compile-command
                       `(format "cd %s && make"
                                (locate-dominating-file buffer-file-name
                                                        ".dir-locals.el"))))
         ;; In C code indentation is 4 spaces and in C++ 2 spaces
         (c++-mode
          (indent-tabs-mode . nil)
          (c-basic-offset . 2))
         (c-mode
          (indent-tabs-mode . nil)
          (c-basic-offset . 4)
          (c-file-style . "BSD")
          (whitespace-style face lines indentation:space))
         )))

