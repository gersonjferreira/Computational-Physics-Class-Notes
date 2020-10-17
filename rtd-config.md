# Read the docs template

This is a **read the docs** style template that I intend to use in other projects. 

To implement this template I've used

- The [RunDocs.io](https://rundocs.io/) template
- [Jekyll's](https://jekyllrb.com) documentation

Latex is included via **mathjax**. But to make it work on mardown files, I had to call at least one a math statement in the **index.rst** file.

Another option is to add the *_includes/extra/head.html* file, so that the template loads **mathjax** manually from there. This might change in the future. See discussions:

- [MathJax not rendering on .github.io](https://github.com/github/pages-gem/issues/307)
- [Painful Upgrade to MathJax 3](https://chrisyeh96.github.io/2020/03/29/mathjax3.html)

The code to add to *_includes/extra/head.html* is:

```html
 <!-- <script type="text/x-mathjax-config">
    MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
</script> -->
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({
        extensions: ["tex2jax.js"],
        jax: ["input/TeX", "output/HTML-CSS"],
        tex2jax: {
            inlineMath: [ ['$','$'], ["\\(","\\)"] ],
            displayMath: [ ['$$','$$'], ["\\[","\\]"] ],
            processEscapes: true
        },
    "HTML-CSS": { availableFonts: ["TeX"] }
  });
</script>
<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>
```
