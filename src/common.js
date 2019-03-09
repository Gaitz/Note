(function () {
  'use strict'

  function handleNavigatorButton () {
    const navigatorMap = document.getElementById("js-navigatorMap");
    navigatorMap.classList.remove("hide");
    navigatorMap.classList.add("show");
  }

  const navigatorButton = document.getElementById("js-navigatorButton");
  navigatorButton.onclick = handleNavigatorButton;
})();