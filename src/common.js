(function () {
  'use strict'

  function handleNavigatorButton () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    navigatorMap.classList.remove("hide");
    navigatorMap.classList.add("show");
  }

  function handleLightBoxClick () {
    const navigatorMap = document.getElementById("js-lightBoxContainer");
    navigatorMap.classList.remove("show");
    navigatorMap.classList.add("hide");
  }

  function handleLightBoxScroll (event) {
    event.preventDefault();
    event.stopPropagation();
  }

  /* main process */
  const navigatorButton = document.getElementById("js-navigatorButton");
  navigatorButton.onclick = handleNavigatorButton;

  const lightBoxContainer = document.getElementById("js-lightBoxContainer");
  lightBoxContainer.onclick = handleLightBoxClick;
  lightBoxContainer.onscroll = handleLightBoxScroll;
})();