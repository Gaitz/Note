(function () {
  'use strict'

  function handleNavigatorButton () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    navigatorMap.classList.remove("hide");
    navigatorMap.classList.add("show");
  }

  /* main process */
  const navigatorButton = document.getElementById("js-navigatorButton");
  navigatorButton.onclick = handleNavigatorButton;
})();