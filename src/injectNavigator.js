(function () {
  'use strict'

  /* main process */
  const pageTitle = document.title
  const navigatorElementOnPage = document.getElementsByTagName("nav").item(0)
  navigatorElementOnPage.innerHTML = `
  <nav class="websiteNav">
    <div class="navigatorBar">
      <p class="whereDescription"><span class="where">所在地 :</span><b>${pageTitle}</b></p>
      <p class="navigatorButton" id="js-navigatorButton">移 動</p>
    </div>

    <div id="js-lightBoxContainer" class="lightBoxContainer hide">
      <ul id="js-navigatorMap" class="navigatorMap">
        <li>
          <a href="../../index.html">About System</a>
        </li>
        <li class="others">
          <a href="../others/Ideas.html">Ideas</a>
          <a href="../others/Display_All.html">Display All</a>
          <a href="../others/Display_Computer_Science.html">Display Computer Science</a>
          <a href="../others/Display_Manner.html">Display Manner</a>
          <a href="../others/Display_Reading_Note.html">Display Reading Note</a>
          <a href="../others/Display_Way_of_Learning.html">Display Way of Learning</a>
        </li>
        <li>
          <a href="../quests/Display_Quests.html">Display Quests</a>
          <a href="../quests/Learning_Path.html">Learning Path</a>
        </li>
        <li>
          <a href="../records/Record_Books.html">Record Books</a>
          <a href="../records/Record_Cook.html">Record Cook</a>
          <a href="../records/Record_Workout.html">Record Workout</a>
          <a href="../records/Record_Questions.html">Record Questions</a>
        </li>
        <li>
          <a href="../toolboxes/Toolbox_Anki_Personal_Note.html">Anki Personal Note</a>
          <a href="../toolboxes/Toolbox_Finding_The_Way_to_Learn_Languages.html">Finding The Way to Learn
            Languages</a>
          <a href="../toolboxes/Toolbox_HTML.html">HTML</a>
          <a href="../toolboxes/Toolbox_History_of_Mathematics.html">History of Mathematics</a>
          <a href="../toolboxes/Toolbox_Markdown_Language.html">Markdown Language</a>
          <a href="../toolboxes/Toolbox_Reading_Note_Fluent_Forever.html">Reading Note Fluent Forever</a>
          <a href="../toolboxes/Toolbox_Reading_Note_Language_Learning_with_Anki.html">Reading Note Learning with
            Anki</a>
          <a href="../toolboxes/Toolbox_Time_Management.html">Time Management</a>
          <a href="../toolboxes/Toolbox_GitHub.html">GitHub</a>
          <a href="../toolboxes/Toolbox_CSS.html">Toolbox CSS</a>
          <a href="../toolboxes/Toolbox_Dress.html">Toolbox Dress</a>
          <a href="../toolboxes/Toolbox_English_Learning.html">Toolbox English Learning</a>
          <a href="../toolboxes/Toolbox_IPA.html">Toolbox IPA</a>
          <a href="../toolboxes/Toolbox_Learning_Method.html">Toolbox Learning Method</a>
          <a href="../toolboxes/Toolbox_Install_Ubuntu.html">Toolbox Install Ubuntu</a>
          <a href="../toolboxes/Toolbox_Python.html">Toolbox Python</a>
          <a href="../toolboxes/Toolbox_Reading_Note_The_Intelligent_Investor.html">Toolbox Reading Note The
            Intelligent
            Investor</a>
          <a href="../toolboxes/Toolbox_Vim.html">Toolbox Vim</a>
        </li>
      </ul>
    </div>
  </nav>
  `
})()